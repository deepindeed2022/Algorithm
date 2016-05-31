# install dev dependency package
for pack in $(cat package.txt); do sudo apt-get install $pack -y; done

# pip install package for python dev
for req in $(cat requistionlist.txt); do sudo pip install $req; done
