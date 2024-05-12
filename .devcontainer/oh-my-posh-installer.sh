#!/usr/bin/env bash
mkdir -p ~/bin
curl -s https://gist.githubusercontent.com/MRDGH2821/47294f0c61f3c9f061e8ffd28e1a538b/raw/6ba2e9436e5ef3b341485bbd3ac12678d650444a/oh-my-posh-random.sh >>~/.bashrc

export PATH=~/bin:$PATH

curl -s https://ohmyposh.dev/install.sh | bash -s -- -d ~/bin

oh-my-posh font install Meslo
