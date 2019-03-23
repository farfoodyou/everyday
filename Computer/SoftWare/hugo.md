# Hugo 教程
    hugo - hugo builds your site
[toc]
## 
hugo new site qs
cd qs

git init
git submodule add https://github.com/olOwOlo/hugo-theme-even.git themes/even
echo 'theme = "even"' >> config.toml

##### 参考资料
[官方QuickStart][1]

[1]: https://gohugo.io/getting-started/quick-start/