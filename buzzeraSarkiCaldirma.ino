const int buton = 3;
const int buzzer = 7;
const int ledPinleri[] = {13, 12, 11, 10, 9, 8};
const int ledSayisi = 6;

// "Let It Go" Nota Frekansları (Hz)
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_A4S 466 // LA Diyez / B♭
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_DS5 622 // RE Diyez / E♭
#define NOTE_F5  698

// Uzatılmış Melodi Dizisi (35 Nota)
int melodi[] = {
  NOTE_G4, NOTE_A4, NOTE_C5, 
  NOTE_C5, NOTE_D5, NOTE_A4S, 
  NOTE_G4, NOTE_A4, NOTE_C5, 
  NOTE_C5, NOTE_D5, NOTE_F5, 
  
  NOTE_G4, NOTE_A4, NOTE_C5, 
  NOTE_C5, NOTE_D5, NOTE_DS5, 
  NOTE_DS5, NOTE_D5, NOTE_C5,
  
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_DS5, NOTE_D5,
  NOTE_C5, NOTE_D5, NOTE_DS5,
  NOTE_D5, NOTE_C5, NOTE_A4S,
  NOTE_C5, NOTE_D5, NOTE_F5, NOTE_G4
};

// Ritim Süreleri (35 Eleman - Düzeltildi)
int ritimler[] = {
  4, 4, 2,
  4, 4, 2,
  4, 4, 4,
  4, 4, 2,
  
  4, 4, 2,
  4, 4, 2,
  4, 4, 2,

  4, 4, 4, 4, 2,
  4, 4, 2,
  4, 4, 2,
  4, 4, 4, 1
};

// Notalarla Eşleşen Gösterim Metinleri (35 Eleman - Düzeltildi)
String sozler[] = {
   "Let ", "it ", "go! \n", 
  "Let ", "it ", "go! \n", 
  "Can't ", "hold ", "it ", 
  "back ", "a-", "ny-more! \n", 

  "Let ", "it ", "go! \n", 
  "Let ", "it ", "go! \n", 
  "Turn ", "a-", "way... \n\n", 

  "Here ", "I ", "stand ", "and ", "here ", 
  "I'll ", "stay... ", "Let ", 
  "the ", "storm ", "rage ", 
  "on... ", "* Cold ", "ne-ver ", 
  "bothered me ", "any-way * \n"

};

int toplamNota = sizeof(melodi) / sizeof(melodi[0]);

bool sarkiCaliyor = false;
int sonButonDurumu = LOW;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < ledSayisi; i++) {
    pinMode(ledPinleri[i], OUTPUT);
  }

  pinMode(buton, INPUT);
  pinMode(buzzer, OUTPUT);
}

void ledleriSondur() {
  for (int i = 0; i < ledSayisi; i++) {
    digitalWrite(ledPinleri[i], LOW);
  }
}

bool butonBastimi() {
  int okunan = digitalRead(buton);
  bool basildi = false;

  if (okunan == HIGH && sonButonDurumu == LOW) {
    delay(30); // Debounce
    if (digitalRead(buton) == HIGH) {
      basildi = true;
    }
  }
  sonButonDurumu = okunan;
  return basildi;
}

// Delay süresini küçük parçalara bölerek buton basışını sürekli dinleyen fonksiyon
bool hassasBekleme(int beklemeSuresi) {
  int gecenSure = 0;
  while (gecenSure < beklemeSuresi) {
    if (butonBastimi()) {
      return true; // Bekleme esnasında butona basıldı!
    }
    delay(10);
    gecenSure += 10;
  }
  return false;
}

void loop() {
  if (!sarkiCaliyor) {
    if (butonBastimi()) {
      sarkiCaliyor = true;
      Serial.println("\n=================================");
      Serial.println("     FROZEN - LET IT GO          ");
      Serial.println("=================================\n");
    }
  }

  if (sarkiCaliyor) {
    for (int i = 0; i < toplamNota; i++) {

      Serial.print(sozler[i]);

      int temelSure = 1100 / ritimler[i];
      int calmaSuresi = temelSure * 0.75;
      int duraklamaSuresi = temelSure * 0.25;

      int aktifLed = i % ledSayisi;
      digitalWrite(ledPinleri[aktifLed], HIGH);

      tone(buzzer, melodi[i], calmaSuresi);

      // Nota çalınırken butona basıldı mı kontrol et
      if (hassasBekleme(calmaSuresi)) {
        sarkiCaliyor = false;
        break;
      }

      noTone(buzzer);
      digitalWrite(ledPinleri[aktifLed], LOW);

      // Notalar arasındaki es esnasında butona basıldı mı kontrol et
      if (hassasBekleme(duraklamaSuresi)) {
        sarkiCaliyor = false;
        break;
      }
    }

    // Şarkı bittiyse veya butonla kesildiyse temizlik yap
    ledleriSondur();
    noTone(buzzer);

    if (!sarkiCaliyor) {
      Serial.println("\n--- Müzik Durduruldu ---");
    } else {
      sarkiCaliyor = false;
      Serial.println("\n=== Şarkı Bitti (Tekrar Çalmak İçin Butona Bas) ===\n");
    }
    delay(300);
  }
}