#ifndef CLA_H_
#define CLA_H_


class Cd{
private:
  char *performers; //연주자
  char *label; //음반사
  int selections; //곡목 수
  double playtime; //분

public:
  Cd(const Cd& d);
  Cd(char *s1= "none", char *s2= "none", int n = 0, double x= 0.0);
  virtual ~Cd();
  virtual void Report() const;
  Cd& operator=(const Cd &d);
};

class Classic : public Cd{
private:
  char *represent;
  
public:
  Classic(char *primary = "none", char *s1 = "none", char *s2 = "none", int n = 0, double x = 0.0);
  Classic(const Cd &d, char *primary);
  Classic(const Classic &x);
  ~Classic();
  virtual void Report() const;
  Classic &operator=(const Classic &x);
}

#endif
