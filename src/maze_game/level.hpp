#ifndef LEVEL_HPP
#define LEVEL_HPP

class Board;

/// @brief Level class
class Level_interface
{
public:
        Level_interface(int, int, int, int);

        virtual ~Level_interface();

public:

        virtual void changeState(Board*) = 0;

        virtual int get_column() const = 0;
        virtual int get_row() const = 0;
        virtual int get_delta_column() const = 0;
        virtual int get_delta_row() const = 0;

protected:
        const int m_column;
        const int m_row;
        const int m_delta_column;
        const int m_delta_row;
};

class Level1 : public Level_interface
{
public:
        Level1();

        ~Level1();
public:

        virtual void changeState(Board*);

        virtual int get_column() const;
        virtual int get_row() const;
        virtual int get_delta_column() const;
        virtual int get_delta_row() const;
};

class Level2 : public Level_interface
{
public:
        Level2();

        ~Level2();
public:
        virtual void changeState(Board*);

        virtual int get_column() const;
        virtual int get_row() const;
        virtual int get_delta_column() const;
        virtual int get_delta_row() const;
};

class Level3 : public Level_interface
{
public:
        Level3();

        ~Level3();
public:
        virtual void changeState(Board*);

        virtual int get_column() const;
        virtual int get_row() const;
        virtual int get_delta_column() const;
        virtual int get_delta_row() const;
};

#endif
