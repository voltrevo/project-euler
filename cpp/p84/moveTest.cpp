class MoveNotCopy
{
private:
    MoveNotCopy(const MoveNotCopy&) { }

public:
    MoveNotCopy() { }
    MoveNotCopy(MoveNotCopy&&) { }
};

MoveNotCopy Foo()
{
    MoveNotCopy mnc;
    
    return mnc;
}

int main()
{
    MoveNotCopy mnc(Foo());
    
    return 0;
}
