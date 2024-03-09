#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>

using std::cout;
using std::endl;
using namespace log4cpp;

void test0() {
    // 1.创建目的地对象
    OstreamAppender * posAp = new OstreamAppender("console", &cout);
    // 2.设置目的地日志布局
    posAp->setLayout(new BasicLayout());

    // 3.创建 Category 对象
    Category & root = Category::getRoot();
    // 4.设置优先级
    root.setPriority(Priority::ERROR);

    root.setAppender(posAp);
    Category & module1 = root.getInstance("register");

    // 5.进行日志记录
    root.emerg("this is an emerge message");
    module1.debug("xxxx");
    // 6.释放申请资源，回收日志系统
    Category::shutdown();
}

int main() {
    test0();
}
