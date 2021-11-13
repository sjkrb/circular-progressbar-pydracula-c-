#ifndef CIRCULARPROGRESSBAR_H
#define CIRCULARPROGRESSBAR_H

#include <QTextDocument>
#include <QWidget>
class CircularProgressBar : public QWidget
{
    Q_OBJECT
public:
    explicit CircularProgressBar(QWidget *parent = nullptr);

    void setValue(float value);
    float value() const;

    void setText_color(const QColor &text_color);

    void setProgress_color(const QColor &progress_color);

    void setEnable_shadow(bool enable_shadow);

    void setProgress_rounded_cap(bool progress_rounded_cap);

    void setMax_value(int max_value);

    void setProgress_width(int progress_width);

    void setHeight(int height);
    int height() const;

    void setWidth(int width);
    int width() const;

    void add_shadow(bool enable);

    void setCircle_color(const QColor &circle_color);

    void setText(const QString &text);

    void setBg_progress_color(const QColor &bg_progress_color);


    void setMargin(int margin);


public slots:
    void _onValueChange(float value);
    void _onTextChange(QString str);

private:
    float           m_value;
    int             m_width;
    int             m_height;
    int             m_progress_width;
    int             m_max_value;
    int             m_margin;
    bool            m_progress_rounded_cap;
    bool            m_enable_shadow;
    QColor          m_progress_color;
    QColor          m_text_color;
    QColor          m_circle_color;
    QColor          m_bg_progress_color;
    QString         m_text;


protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CIRCULARPROGRESSBAR_H
