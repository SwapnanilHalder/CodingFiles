# BACKUP ALL SETTINGS

dconf dump /org/cinnamon/ > /home/swapno/Documents/CodingFiles/script_backups/linux_mint/cinnamon.dconf
dconf dump /org/nemo/ > /home/swapno/Documents/CodingFiles/script_backups/linux_mint/nemo.dconf
dconf dump /org/gtk/ > /home/swapno/Documents/CodingFiles/script_backups/linux_mint/gtk.dconf
dconf dump /org/gnome/ > /home/swapno/Documents/CodingFiles/script_backups/linux_mint/gnome.dconf


# RESTORE ALL SETTINGS

# dconf load /org/cinnamon/ < cinnamon.dconf
# dconf load /org/nemo/ < nemo.dconf
# dconf load /org/gtk/ < gtk.dconf
# dconf load /org/gnome/ < gnome.dconf