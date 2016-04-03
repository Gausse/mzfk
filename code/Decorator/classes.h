#ifndef _CLASSES_H_
#define _CLASSES_H_

class Exception
{
    char* m_sText;
protected:
    Exception* mpPrev;
public:
    Exception(char* msg, Exception* pPrev = 0) : m_sText(msg), mpPrev(pPrev)
    {
        std::cout << "Exception " << "this >> " << this << std::endl;
    }
    virtual ~Exception()
    {
        std::cout << "Exception dest " << "this >> " << this << std::endl;
        delete mpPrev;
    }
    virtual void show()
    {
        if (mpPrev != NULL)
        {
            mpPrev->show();
        }
        std::cout << m_sText << std::endl;
    }
};

class ChException : public Exception
{
protected:
    Exception* mpChPrev;
public:
    ChException(char* msg, Exception* pPrev) : Exception(msg, pPrev), mpChPrev(pPrev)
    {
        std::cout << "ChException " << "this >> " << this << std::endl;
    }
    virtual ~ChException()
    {
        std::cout << "ChException dest " << "this >> " << this << std::endl;
        delete mpPrev;
    }
};

class GrChException : public ChException
{
protected:
    Exception* mpGrChPrev;
public:
    GrChException(char* msg, ChException* pPrev) : ChException(msg, pPrev), mpGrChPrev(pPrev)
    {
        std::cout << "GrChException " << "this >> " << this << std::endl;
    }
    virtual ~GrChException()
    {
        std::cout << "GrChException dest " << "this >> " << this << std::endl;
        delete mpPrev;
    }
};

#endif // _CLASSES_H_
