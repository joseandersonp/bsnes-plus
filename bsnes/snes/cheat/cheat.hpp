struct CheatCode {
  bool enabled;
  array<unsigned> addr;
  array<uint8> data;

  bool operator=(string);
  CheatCode();
};

class Cheat : public linear_vector<CheatCode> {
public:
  enum class Type : unsigned { ProActionReplay, GameGenie };

  bool enabled() const;
  void enable(bool);
  void synchronize();
  bool read(unsigned, uint8&, Bus&) const;

  inline bool active() const;
  inline bool exists(uint16 addr) const;

  Cheat();

  static bool decode(const char*, unsigned&, uint8&, Type&);
  static bool encode(string&, unsigned, uint8, Type);

private:
  uint8 bitmask[0x2000];
  bool system_enabled;
  bool code_enabled;
  bool cheat_enabled;
};

extern Cheat cheat;
