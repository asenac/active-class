#ifndef ACTIVECLASS_HPP
#define ACTIVECLASS_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

class ActiveClass
{
public:

    ActiveClass();
    virtual ~ActiveClass();

    virtual void start();
    virtual void stop();
    virtual void wait();

protected:

    boost::asio::io_service m_io_service;
    boost::asio::io_service::work m_work;
    boost::thread m_thread;
};

#define ASYNC_METHOD(name, params)                                  \
    public:                                                         \
    struct __ ## name ## _t { params; };                            \
    void name(const __ ## name ## _t& p = __ ## name ## _t());      \
    protected:                                                      \
    void __ ## name(const __ ## name ## _t& p);                     \
    /***/

#define ASYNC_METHOD_IMPL(clazz, name)                              \
    void clazz::name(const __ ## name ## _t& p)                     \
    {                                                               \
        m_io_service.post(boost::bind(&clazz::__ ## name, this, p));\
    }                                                               \
    void clazz::__ ## name(const __ ## name ## _t& p)               \
    /***/

#define ASYNC_OR_SYNC_METHOD(name, params)                          \
    ASYNC_METHOD(name, params)                                      \
    /***/

#define ASYNC_OR_SYNC_METHOD_IMPL(clazz, name)                      \
    void clazz::name(const __ ## name ## _t& p = __ ## name ## _t())\
    {                                                               \
        if (m_thread.joinable())                                    \
        m_io_service.post(boost::bind(&clazz::__ ## name, this, p));\
        else                                                        \
        __ ## name(p);                                              \
    }                                                               \
    void clazz::__ ## name(const __ ## name ## _t& p)               \
    /***/

#endif /* ACTIVECLASS_HPP */

