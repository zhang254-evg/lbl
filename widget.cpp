#include "widget.h"
#include "ui_widget.h"
#include <QRegularExpression>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton1_clicked()
{
    expression  += "1";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton2_clicked()
{
    expression  += "2";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton3_clicked()
{
    expression  += "3";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton4_clicked()
{
    expression  += "4";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton5_clicked()
{
    expression  += "5";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton6_clicked()
{
    expression  += "6";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton7_clicked()
{
    expression  += "7";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton8_clicked()
{
    expression  += "8";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton9_clicked()
{
    expression  += "9";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButton0_clicked()
{
    expression  += "0";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButtonF_clicked()
{
    expression  += ".";
    ui->lineEdit->clear();
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButtonX_clicked()
{
    expression  += "*";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButtonD_clicked()
{
    expression  += "/";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButtonP_clicked()
{
    expression  += "+";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButtonM_clicked()
{
    expression  += "-";
    ui->lineEdit->setText(expression);
}


void Widget::on_pushButtonC_clicked()
{
    expression.clear();
    ui->lineEdit->clear();
}


void Widget::on_pushButtonT_clicked()
{
    expression.chop(1);
    ui->lineEdit->backspace();
}


void Widget::on_pushButtonE_clicked()
{
    // Split the expression string into a QStringList based on the operators
    QStringList parts = expression.split(QRegularExpression("[-+*/]"), Qt::KeepEmptyParts);

    // Convert the operands to double type
    QList<double> operands;
    for (const QString& part : parts) {
        if (!part.isEmpty()) {
            operands.append(part.toDouble());
        }
    }

    // Perform multiplication and division first
    double result = operands[0];
    int i = 1;
    while (i < operands.size()) {
        QChar op = expression[i * 2 - 1].toLatin1();
        if (op == '*' || op == '/') {
            switch (op.toLatin1()) {
            case '*':
                result *= operands[i];
                break;
            case '/':
                if (operands[i] == 0) {
                    // Handle the case where the divisor is zero
                   ui->lineEdit->setText("Error,Cannot divide by zero.");
                    return;
                }
                result /= operands[i];
                break;
            }
            i += 2;
        } else {
            break;
        }
    }

    // Perform addition and subtraction
    for (; i < operands.size(); i += 2) {
        QChar op = expression[i * 2 - 1].toLatin1();
        switch (op.toLatin1()) {
        case '+':
            result += operands[i];
            break;
        case '-':
            result -= operands[i];
            break;
        }
    }

    // Display the calculation result in the lineEdit
    ui->lineEdit->setText(QString::number(result));
    // Clear the expression string, ready for the next calculation
    expression.clear();
}
