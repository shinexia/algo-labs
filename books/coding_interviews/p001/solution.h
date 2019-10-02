
class CMyString {
   public:
    CMyString(char* data = nullptr) : data_(data) {}
    CMyString(const CMyString& str);
    ~CMyString();

   private:
    char* data_;
};
