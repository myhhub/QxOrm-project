#include "precompiled.h"
#include "user.h"
#include <QxOrm_Impl.h>

QX_REGISTER_CPP_USER(User)

namespace qx {
    template <> void register_class(QxClass<User> & t)
    {
        // 注册 User::id <=> 数据库中的主键
        t.id(&User::id, "id");

        // 注册 User::name 属性，使用的 key 是 name，version 是 1。
        t.data(&User::name, "name", 1);

        // 注册 User::age 属性，使用的 key 是 age。
        t.data(&User::age, "age");
    }
}
