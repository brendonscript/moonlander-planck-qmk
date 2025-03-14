#!/bin/bash

# Check if gh CLI is installed
if ! command -v gh &>/dev/null; then
  echo "GitHub CLI (gh) is not installed. Please install it first."
  echo "Installation instructions: https://github.com/cli/cli#installation"
  exit 1
fi

# Check if logged in to GitHub
if ! gh auth status &>/dev/null; then
  echo "You need to login to GitHub CLI first. Run 'gh auth login'"
  exit 1
fi

# Define repository
REPO="brendonscript/moonlander-qmk"

# Define layout mapping
declare -A layouts
layouts["1"]="5qJbe:moonlander"
layouts["2"]="e5WnW:planck_ez/glow"

# Show menu
echo "Select a layout to build:"
echo "1) 5qJbe (Moonlander v3)"
echo "2) e5WnW (Planck)"
read -p "Enter selection [1-2]: " choice

# Validate choice
if [[ ! "${layouts[$choice]}" ]]; then
  echo "Invalid selection. Please choose 1, or 2."
  exit 1
fi

# Split the selected layout into ID and geometry
IFS=':' read -r layout_id layout_geometry <<<"${layouts[$choice]}"

echo "Triggering build for $layout_id on $layout_geometry in repository $REPO..."

# Trigger the workflow
gh workflow run fetch-and-build-layout.yml -R "$REPO" -f layout_id="$layout_id" -f layout_geometry="$layout_geometry"

if [ $? -eq 0 ]; then
  echo "Build triggered successfully! Check GitHub Actions for status."
  echo "https://github.com/$REPO/actions"
else
  echo "Failed to trigger workflow. Check if workflow exists and you have permissions."
fi
