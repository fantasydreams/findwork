
struct context {
};

class AbstractDecorator {
    public:
        AbstractDecorator() = default;
        virtual ~AbstractDecorator() = default;
        virtual int Handle(context& oCtx) = 0;
};

// 本质，所有的装饰都是在本质上新增指责
class Essence : public AbstractDecorator {
    public:
        explicit Essence(int val) : m_iValue(val){};
        virtual ~Essence() = default;
        virtual int Handle(context& oCtx) override{
            return m_iValue;
        }
    private:
        int m_iValue;
};


class DoubleDecorator : public AbstractDecorator {
    public:
        DoubleDecorator(AbstractDecorator* poDecorator) : m_poDeco(poDecorator) {};
        virtual ~DoubleDecorator() = default;
        virtual int Handle(context& oCtx) {
            return 2 * m_poDeco->Handle(oCtx);
        }
    private:
        AbstractDecorator* m_poDeco;
};

class HalfDecorator : public AbstractDecorator {
    public:
        HalfDecorator(AbstractDecorator* poDecorator) : m_poDeco(poDecorator) {};
        virtual ~HalfDecorator() = default;
        virtual int Handle(context& oCtx) {
            return m_poDeco->Handle(oCtx) / 2;
        }
    private:
        AbstractDecorator* m_poDeco;
};