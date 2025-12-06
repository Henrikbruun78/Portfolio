1. Install tmux:
sudo apt install tmux

2. Create configuration file:
sudo nano ~/.tmux.conf

3. Enable essential options:
set -g mouse on
set -g default-terminal "tmux-256color"
set -as terminal-overrides ",*:Tc"
setw -g mode-keys vi

4. Install TPM:
git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

5. Add plugins:
In .tmux.conf:
set -g @plugin 'tmux-plugins/tpm'
set -g @plugin 'tmux-plugins/tmux-sensible'
set -g @plugin 'tmux-plugins/tmux-resurrect'
set -g @plugin 'tmux-plugins/tmux-continuum'
set -g @plugin 'tmux-plugins/tmux-yank'
run '~/.tmux/plugins/tpm/tpm'

Install plugins inside tmux:
Ctrl-b  I

6. Default development layout:
Create a command binding:
bind L run-shell '~/.tmux/layouts/dev_layout.sh'
Where the script sets up windows/panes.

