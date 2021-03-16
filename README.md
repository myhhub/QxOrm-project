QxOrm使用教程(ORM for C++ 对象关系映射)

QxOrm 是一个 C++ 库，旨在为 C++/Qt 开发人员提供对象关系映射（ORM）功能（类似于 Java 中的 Hibernate，.Net 中的 NHibernate）。

- **主页：**http://www.qxorm.com/qxorm_en/home.html
- **下载：**http://www.qxorm.com/qxorm_en/download.html
- **手册：**http://www.qxorm.com/qxorm_en/manual.html
- **在线类文档：**http://www.qxorm.com/doxygen/html/index.html
- **GitHub：**https://github.com/QxOrm/QxOrm

其主要特性包括：

- 持久性：支持最常见的数据库，如 SQLite、MySQL、PostgreSQL、Oracle、MS SQL Server、MongoDB（具有 1-1、1-n、n-1 和 n-n 关系）。
- 序列化：JSON、二进制和 XML 格式。
- 反射（或内省）：动态访问类定义、检索属性和调用类方法。
- HTTP Web Server：独立的多线程 HTTP 1.1 web 服务器（支持 SSL/TLS、持久连接、cookie、会话、分块响应、URL 分发器/路由）。
- JSON API：与 C++/Qt 以外的其他技术的互操作性（REST web 服务、QML 应用程序、脚本语言）。

默认情况下，QxOrm 库只依赖 QtCore 和 QtSql 模块。如果启用 QxOrm HTTP web server 特性，那么还将依赖于 QtNetwork 模块。除此之外，有些特性还需要依赖 boost（默认禁用）。

[QxOrm使用教程(ORM for C++ 对象关系映射)](https://www.ljjyy.com/archives/2021/03/100646.html)
