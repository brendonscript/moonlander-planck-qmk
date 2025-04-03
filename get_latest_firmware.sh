#!/bin/bash

# Default values
KEYBOARD="planck"
LAYOUT_ID="agKMo"

# Help message
show_help() {
    echo "Usage: ./get_latest_firmware.sh [-k keyboard] [-l layout_id]"
    echo "Options:"
    echo "  -k    Keyboard type (planck or moonlander) [default: planck]"
    echo "  -l    Layout ID (agKMo for Planck, 5qJbe for Moonlander) [default: agKMo]"
    echo "  -h    Show this help message"
}

# Parse command line options
while getopts "k:l:h" opt; do
    case $opt in
        k) KEYBOARD="$OPTARG" ;;
        l) LAYOUT_ID="$OPTARG" ;;
        h) show_help; exit 0 ;;
        ?) show_help; exit 1 ;;
    esac
done

# Get repository name from git remote
REPO=$(git remote get-url origin | sed 's/.*github.com[:/]\(.*\).git/\1/')

echo "Fetching latest successful workflow artifact..."

# Get the latest successful workflow run ID
RUN_ID=$(gh run list --repo "$REPO" --workflow "Fetch and build layout" --status success --limit 1 --json databaseId -q '.[0].databaseId')

if [ -z "$RUN_ID" ]; then
    echo "Error: No successful workflow runs found"
    exit 1
fi

# Download the artifact
DOWNLOAD_DIR="firmware_downloads"

echo "Downloading artifact from run $RUN_ID..."
rm -rf "$DOWNLOAD_DIR"  # Clean previous downloads
mkdir -p "$DOWNLOAD_DIR"

# List available artifacts
echo "Available artifacts:"
gh run view "$RUN_ID" --repo "$REPO"

# Use pattern matching for more flexible artifact finding
if [[ "$KEYBOARD" == "moonlander" ]]; then
    ARTIFACT_PATTERN="*moonlander*${LAYOUT_ID}*"
else
    ARTIFACT_PATTERN="*planck*${LAYOUT_ID}*"
fi

echo "Attempting to download artifacts matching pattern: $ARTIFACT_PATTERN"
gh run download "$RUN_ID" --repo "$REPO" --pattern "$ARTIFACT_PATTERN" --dir "$DOWNLOAD_DIR"

echo "Contents of download directory:"
ls -la "$DOWNLOAD_DIR"

# Find the downloaded firmware file
if [[ "$KEYBOARD" == "moonlander" ]]; then
    FIRMWARE_FILE=$(find "$DOWNLOAD_DIR" -type f -name "*.bin" -print -quit 2>/dev/null)
else
    # For Planck, look for both .hex and .bin files since the format might vary
    FIRMWARE_FILE=$(find "$DOWNLOAD_DIR" -type f \( -name "*.hex" -o -name "*.bin" \) -print -quit 2>/dev/null)
fi

echo "Looking for firmware files..."
find "$DOWNLOAD_DIR" -type f -ls

if [ -z "$FIRMWARE_FILE" ]; then
    echo "Error: Firmware file not found in the artifact!"
    exit 1
fi

echo "Successfully downloaded firmware to: $FIRMWARE_FILE"
echo "To flash your keyboard:"
echo "1. Put your keyboard in reset mode"
echo "2. Run: qmk flash $FIRMWARE_FILE"
