#remember to rename base to /<reponame>/ first
vuepress build docs
cd docs/.vuepress/dist
git init
git add -A
git config --global user.name "Alan Tsui"
git config --global user.email "1155110323@link.cuhk.edu.hk"
git commit -m 'deploy'
git push -f git@github.com:heihaho/UGEA2190.git master:gh-pages

