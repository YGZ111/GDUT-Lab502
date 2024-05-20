#ifndef CONTROL_PAGE_H
#define CONTROL_PAGE_H

#include <QWidget>

namespace Ui {
class control_page;
}

class control_page : public QWidget
{
    Q_OBJECT

public:
    explicit control_page(QWidget *parent = nullptr);
    ~control_page();

private:
    Ui::control_page *ui;
};

#endif // CONTROL_PAGE_H
