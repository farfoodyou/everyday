#### Git Setting
关闭中文文件名乱码（8进制）？

    git config --global core.quotepath false
    git config --global gui.encoding utf-8

#### git clone
git clone git@github.com:farfoodyou/everyday.git
git clone git@github.com:用户名/仓库名.git
远程的仓库一般都是以.git为结尾的。


#### 初始化用户名和邮箱
git config --global user.name "Author Name"
git config --global user.email "your_email@example.com"

git config user.name "Author Name"
git config user.email "Author Email"

#### 强制上传版本库
确认无误后，提交至版本库（切记，下面的操作将不可逆）
git push origin --force --all
git push origin --force --tags

#### git pull / merge / fetch
