/****************************************
* @file    Export
* @brief   管理类、函数 ... 的导出/导入。
* @author  Waleon
* @wechat  微信公众号：高效程序员
* @date    2020/02/07
****************************************/


#ifndef EXPORT_H
#define EXPORT_H

#ifdef _BUILDING_USER
#define USER_DLL_EXPORT  QX_DLL_EXPORT_HELPER
#else
#define USER_DLL_EXPORT  QX_DLL_IMPORT_HELPER
#endif

#ifdef _BUILDING_USER
#define QX_REGISTER_HPP_USER  QX_REGISTER_HPP_EXPORT_DLL
#define QX_REGISTER_CPP_USER  QX_REGISTER_CPP_EXPORT_DLL
#else
#define QX_REGISTER_HPP_USER  QX_REGISTER_HPP_IMPORT_DLL
#define QX_REGISTER_CPP_USER  QX_REGISTER_CPP_IMPORT_DLL
#endif

#endif // EXPORT_H
