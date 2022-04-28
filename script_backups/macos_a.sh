cp ~/library/preferences/com.apple.dock.plist ~/com.apple.dock.plist
brew update && brew upgrade && brew upgrade --cask && brew upgrade --greedy
defaults import com.apple.dock.plist ~/com.apple.dock.plist
killall Dock
rm ~/com.apple.dock.plist
