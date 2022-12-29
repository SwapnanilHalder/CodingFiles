cp ~/library/preferences/com.apple.dock.plist ~/com.apple.dock.plist
echo "Running brew update & upgrade"
brew update && brew upgrade && brew upgrade --cask && brew upgrade --greedy
echo "Showing all formulae that were only installed as a dependency of another formula and are now no longer needed."
brew autoremove -n
echo "to remove these, run brew autoremove"
echo "Running brew cleanup"
brew cleanup
echo "Running brew doctor"
brew doctor
defaults import com.apple.dock.plist ~/com.apple.dock.plist
killall Dock
rm ~/com.apple.dock.plist
