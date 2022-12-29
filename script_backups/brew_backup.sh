rm ~/Documents/CodingFiles/script_backups/Brewfile
echo "Older Brewfile removed"
brew tap Homebrew/bundle
brew bundle dump
echo "Brew bundle dumped in current directory"
mv Brewfile ~/Documents/CodingFiles/script_backups/Brewfile
echo "Brewfile moved to ~/Documents/CodingFiles/script_backups/Brewfile"