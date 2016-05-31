#!/bin/bash
# install software in list
for req in $(cat install_software.txt); do sudo apt-get install $req; done

# install sublime
wget -P $HOME/Downloads/ https://download.sublimetext.com/Sublime%20Text%202.0.2%20x64.tar.bz2  
tar -xjvf $HOME/Downloads/Sublime\ Text\ 2.0.2\ x64.tar.bz2 
mkdir /opt/Sublime_Text_2
mv  $HOME/Downloads/Sublime\ Text\ 2.0.2/  /opt/SublimeText2
ln -s /opt/SublimeText2/sublime_text /usr/local/bin/subl

