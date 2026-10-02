# arduino-melody-led-show
🎵 Arduino Melody & LED Show

Arduino Uno kullanılarak geliştirilen, buton ile kontrol edilen bir buzzer ve LED müzik projesidir.

🎯 Proje Hakkında

Butona basıldığında buzzer üzerinden Let It Go melodisinin Arduino için düzenlenmiş bir versiyonu çalınır. Melodi boyunca 6 LED sırayla yanarak görsel bir efekt oluşturur.

Şarkı çalarken butona tekrar basılarak müzik durdurulabilir.

🛠️ Kullanılan Malzemeler
Arduino Uno
Buzzer
6 adet LED
Push Button
Dirençler
Jumper kablolar
Breadboard
💻 Kullanılan Teknolojiler
C/C++
Arduino
Digital I/O
tone() / noTone()
Serial Monitor
Buton kontrolü
LED kontrolü
⚙️ Özellikler
Buton ile müziği başlatma
Buton ile müziği durdurma
Buzzer ile melodi çalma
Melodiye göre LED animasyonu
Nota sürelerinin ritim dizisi üzerinden kontrol edilmesi
Serial Monitor üzerinden şarkı sözlerinin gösterilmesi
Buton için debounce kontrolü
Müzik çalarken buton girişini sürekli kontrol etme

🔌 Pin Bağlantıları
Bileşen	Arduino Pin
Push Button	D3
Buzzer	D7
LED 1	D13
LED 2	D12
LED 3	D11
LED 4	D10
LED 5	D9
LED 6	D8


▶️ Nasıl Çalıştırılır?
Arduino devresini bağlantı tablosuna göre kurun.
LetItGo.ino dosyasını Arduino IDE ile açın.
Arduino Uno'ya yükleyin.
Serial Monitor'ü 9600 baud hızında açın.
Butona basarak melodiyi başlatın.
Müzik sırasında butona tekrar basarak melodiyi durdurun.

📌 Öğrenilen Konular

Bu projede Arduino üzerinde:

Diziler
Fonksiyonlar
Döngüler
Koşul ifadeleri
Dijital giriş/çıkış
Buzzer ile ses üretimi
Nota frekansları
LED kontrolü
Buton debounce
Zamanlama ve ritim
Serial iletişim

konuları uygulanmıştır.

🚀 Geliştirme Fikirleri
Farklı şarkıların eklenmesi
Daha fazla LED efekti
Potansiyometre ile ses/tempo kontrolü
Birden fazla buton ile farklı melodilerin seçilmesi
Daha gelişmiş müzik notasyonu

Project: Arduino Melody & LED Show
Language: C/C++
Platform: Arduino Uno
