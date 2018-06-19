#ifndef MOTOR_H
#define MOTOR_H


class Motor
{
    public:
        Motor();
        bool getEncendido();
        void setEncendido(bool);

    protected:

    private:
        bool encendido;
};

#endif // MOTOR_H
