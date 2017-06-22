## Apache开启CGI
 +
 +* 需要在apache中开启cgi支持.
 +* sudo ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load
 +* 需要重启 apache 服务器
 +* service apache2 restart
 +* 需要运行的cgi文件的存放路径为:
 +* /usr/lib/cgi-bin
 +* 改完目录的权限, 方便对目录下的文件写.
 +* sudo mkdir /usr/lib/cgi-bin/sx
 +* sudo chmod 777 /usr/lib/cgi-bin/sx
 +
 +## Makefile.
 +* vim Makefile
 +
 +* install:
 +	cp *.cgi /usr/lib/cgi-bin/sx
 +
 +## 安装mysql的C语言库
 +* sudo apt-get update
 +* sudo apt-get install libmysqlclient-dev
