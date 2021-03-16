#include "precompiled.h"
#include "user.h"
#include <QxOrm_Impl.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 初始化参数，用于和数据库交互
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("./Users.db");
    qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
    qx::QxSqlDatabase::getSingleton()->setUserName("root");
    qx::QxSqlDatabase::getSingleton()->setPassword("");

    // 在数据库中创建 User 表
    QSqlError daoError = qx::dao::create_table<User>();

    // 创建 3 个用户
    // 可以使用 std 和 Qt 智能指针：std::shared_ptr、QSharedPointer 等...
    typedef  QSharedPointer<User> UserPtr;
    UserPtr u1;
    u1.reset(new User());
    u1->name = "Jack Ma";
    u1->age = 30;

    UserPtr u2;
    u2.reset(new User());
    u2->name = "Pony";
    u2->age = 25;

    UserPtr u3;
    u3.reset(new User());
    u3->name = "Waleon";
    u3->age = 18;

    // 将所有用户插入容器中
    // 可以使用 std、boost、Qt 和 qx::QxCollection<Key，Value> 中的许多容器
    typedef QVector<UserPtr> VectorUser;
    VectorUser users;
    users.push_back(u1);
    users.push_back(u2);
    users.push_back(u3);

    // 将容器中的所有用户插入到数据库中
    // p1、p2、p3 的 id 属性会自动更新
    daoError = qx::dao::insert(users);

    // 修改第二个用户的信息，并更新到数据库中
    u2->name = "Pony modified";
    u2->age = 38;
    daoError = qx::dao::update(u2);

    // 从数据库中删除第一个用户
    daoError = qx::dao::delete_by_id(u1);

    // 计算用户的数量
    long userCount = qx::dao::count<User>();
    qDebug() << "User Count: " << userCount;

    // 将 id 为 3 的用户取出，并传给一个新变量
    UserPtr userTmp;
    userTmp.reset(new User());
    userTmp->id = 3;
    daoError = qx::dao::fetch_by_id(userTmp);
    qDebug() << "User Tmp: " << userTmp->id << userTmp->name << userTmp->age;

#if _QX_SERIALIZE_XML
    // 将容器中的用户导出到 XML 文件中（序列化）
    qx::serialization::xml::to_file(users, "./export_users.xml");

    // 将 XML 中的用户导入至新容器
    VectorUser usersXmlTmp;
    qx::serialization::xml::from_file(usersXmlTmp, "./export_users.xml");
#endif

#ifndef _QX_NO_JSON
    // 将容器中的用户导出到 Json 文件中（序列化）
    qx::serialization::json::to_file(users, "./export_users.json");

    // 将 Json 文件中的用户导入至新容器
    VectorUser usersJsonTmp;
    qx::serialization::json::from_file(usersJsonTmp, "./export_users.json");
#endif

    // 克隆一个用户
    UserPtr uClone = qx::clone_to_qt_shared_ptr(*u1);
    qDebug() << "Clone from u1: " << uClone->id << uClone->name << uClone->age;

    // 按类名（factory）创建新用户
    qx::any uAny = qx::create("User");

    // 将用户插入到 qx::cache
    qx::cache::set("users", users);

    // 从 qx::cache 中删除所有元素
    qx::cache::clear();

    // 内存泄漏
    User *user = new User();

    return a.exec();
}
