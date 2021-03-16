/****************************************
* @file    User
* @brief   对应的是数据库中的 User 表
* @author  Waleon
* @wechat  微信公众号：高效程序员
* @date    2020/02/07
****************************************/

#ifndef USER_H
#define USER_H

class USER_DLL_EXPORT User
{
public:
    User() : id(0) { }
    virtual ~User() { }

    long id;
    QString name;
    int age;
};

QX_REGISTER_HPP_USER(User, qx::trait::no_base_class_defined, 1)

#endif // USER_H
