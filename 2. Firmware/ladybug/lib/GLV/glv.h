#ifndef GLV_H
#define GLV_H

class GLV {
public:
  void setup();
  void read();

  bool get_glv_l();
  bool get_glv_r();

  GLV(){
    setup();
  }

private:
  static const int _GLV_PIN_R = 18;
  static const int _GLV_PIN_L = 26;

};

extern GLV Glv;

#endif 