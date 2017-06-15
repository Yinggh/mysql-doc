# 在 Linux 下使用 mysql
## 在 Linux 下安装 mysql
1. 在 vim .vimrc 中删除第18行（完成后在vim编辑时可以复制/粘贴文本）；
2. 使用 sudo vim /etc/apt/sources.lis 命令将源粘贴到源列表中；
   源附录：
   deb http://mirrors.aliyun.com/ubuntu/ xenial main restricted universe multiverse
   deb http://mirrors.aliyun.com/ubuntu/ xenial-security main restricted universe multiverse
   deb http://mirrors.aliyun.com/ubuntu/ xenial-updates main restricted universe multiverse
   deb http://mirrors.aliyun.com/ubuntu/ xenial-backports main restricted universe multiverse
   ###### 测试版源
   deb http://mirrors.aliyun.com/ubuntu/ xenial-proposed main restricted universe multiverse
   ###### 源码
   deb-src http://mirrors.aliyun.com/ubuntu/ xenial main restricted universe multiverse
   deb-src http://mirrors.aliyun.com/ubuntu/ xenial-security main restricted universe multiverse
   deb-src http://mirrors.aliyun.com/ubuntu/ xenial-updates main restricted universe multiverse
   deb-src http://mirrors.aliyun.com/ubuntu/ xenial-backports main restricted universe multiverse
   ###### 测试版源
   deb-src http://mirrors.aliyun.com/ubuntu/ xenial-proposed main restricted universe multiverse
   ###### Canonical 合作伙伴和附加
   deb http://archive.canonical.com/ubuntu/ xenial partner
   deb http://extras.ubuntu.com/ubuntu/ xenial main
### Apache安装
3. 使用 sudo apt-get update 命令更新数据；
4. 使用 sudo apt-get install tasksel 和 sudo tasksel 命令安装Apache（包含mysql）；安装过程中设置用户root的密码为123456；
5. 使用 mysql -u root -p 命令回车后系统会提示你输密码，然后进入mysql操作页面；
6. 创建一个数据库叫stu
7. 数据库下创建三个表，分别为：学生信息表（information），院校表（school），成绩表（score）。
