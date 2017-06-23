### www.github.com
1.  创建一个outlook邮箱账号
2.  利用该账号创建github 账号
### 远程仓库
1.添加远程仓库
如果我们现在本地有一个git仓库, 我们使用remote add 命令将它添加到远程的仓库中.
$ git remote add origin https://github.com/chenmuer/mysql-doc.git
并需要将远程的仓库的信息更步到本地, 这里主要指的示远程仓库的分支和远程库的提交变更信息.
$ git fetch origin
2.向远程仓库提交
* （1）同步master分支
如果我们本地的仓库进行开发, 交进行提交commit. 那么我们本地的仓库和远程的仓库就不能保持同步了.那么我们需要把本地的这次提交也要反映在远程的仓库上. 那么我们就需要使用push命令.
$ git push origin master
* （2）同步其它分支
如果我们需要我们其它分支的提交也要反映在远程库中. 如果远程没有这个分支, 它就会自动创建这个分支.
$ git push origin branch-name
* （3）同步标签
使用git push origin branch-name命令不会将本地打好的标签同步(推送)到服务器上, 需要使用下面的命令将本地的tags同步(推送)到服务器上.
git push origin --tags
* （4）删除远程分支
可以用这个非常有意思的语法来删除它：git push [远程名] :[分支名]。 在于分支名前的冒号.
$ git push -u origin :branch-name
* （5）删除远程标签
如果我们也想把远程仓库中是的标签删除.
$ git push origin --delete <branchName>
$ git push origin --delete tag <tagname>
* （6）从远程仓库同步
当我们知道git仓库的地址了(在github上有很多的开源仓库.), 就可以使用下面的命令将源码拉取到本地.
$ git clone url
我们已经拉取源码到本地了, 但是服务器上的git已经更新了, 当我们需要将服务器的源码与本地源友进行同步进时, 需要使用下面的命令.
$ git pull
