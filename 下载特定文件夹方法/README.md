## 描述

下载 github 指定文件夹内容

## 参考：

[🤣 Github | 如何在Github上只下载一个文件或文件夹！？ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/578116206)

## 方法一、 插件 gitzip for github

缺点： 经测试只能打包一级文件夹，可能下载冗余文件

1、Edge 或 谷歌拓展商店搜索  gitzip for github

2、 点击拓展，添加 token

3、刷新github网页 ，在仓库的一级文件树每个文件夹悬停都会有方框，进行选择

4、 右下角有下载按钮

## 方法二、 网站下载 DownGit(最快)

1、登录 DownGit 网站

[DownGit (minhaskamal.github.io)](https://minhaskamal.github.io/DownGit/#/home)

或代替网址https://blog.luckly-mjw.cn/tool-show/github-directory-downloader/index.html

2、登录 github ,进入 github 文件所在目录，复制浏览器地址栏 url

3、在 DownGit 搜索框输入刚刚复制的 url ，解析

## 方法三 SVN 下载

1、下载 SVN

[Subversion for Windows download | SourceForge.net](https://sourceforge.net/projects/win32svn/)

2、登录 github ,进入目标文件目录，复制浏览器地址栏 url,把 url 里面的 "tree" 替换为 "branches"

3、通过 SVN 下载文件

在想要的下载位置进入 cmd (文件资源管理器进入目标目录，地址栏输入cmd 回车)

格式如下：

```text
svn export 替换后的url
```



---

by [Center-cr )](https://github.com/Center-cr)
