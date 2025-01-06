# Otonom Araç Kontrol Sistemi

Bu proje, otonom bir aracın temel kontrol ve yönetim sistemini sağlamaya yönelik bir uygulamayı kapsar. Sistem, belirli bir algoritmayı takip ederek aracın çevresini algılayabilir, rota planlaması yapabilir ve belirlenen hedeflere başarıyla ulaşabilir.

## Özellikler

- Sensör Tabanlı Algılama: Çevresel engellerin algılanması için ultrasonik ve/veya lidar sensörlerin kullanılması.

- Gerçek Zamanlı Karar Verme: Hareket rotasının dinamik olarak planlanması ve engellerden kaçınma.

- Hedef Takibi: Aracın belirlenen GPS koordinatlarına yönelik hareket etmesi.

- Manuel ve Otonom Modlar: Kullanıcı tarafından kontrol edilebilen veya tamamen otonom bir şekilde çalışan çift mod desteği.

## Gerekli Donanımlar

- Arduino veya benzer bir mikrodenetleyici

- Ultrasonik/Lidar sensör

- DC motor ve motor sürücü modülü

- GPS modülü

- Bluetooth veya Wi-Fi modülü (isteğe bağlı)

- Batarya ve güç yönetim sistemi

## Yazılım Gereksinimleri

- Arduino IDE

- Gerekli kütüphaneler (Proje kodlarında belirtilmiştir.)

## Kurulum

### 1.Donanım Bağlantılarını Yapın:

Sensörleri ve motor sürücülerini uygun şekilde Arduino'ya bağlayın.

GPS modülünü UART portuna bağlayın.

### 2.Kodu Yüklen:

Arduino IDE'yi kullanarak aa.ino dosyasını Arduino'ya yükleyin.

### 3.Test Edin:

Sistemi başlatın ve sensörlerin doğru çalıştığını doğrulamak için seri monitörü kullanın.

Manuel veya otonom modu seçerek sistemi test edin.

## Kullanım

 1. Güç kaynağını açın.

 2. Sensörlerin ve modüllerin doğru çalıştığını kontrol edin.

 3. İstenilen modda araca komut verin:

 - Manuel mod: Uzaktan kumanda veya uygulama ile kontrol.

 - Otonom mod: Araç, programlanmış algoritmaları kullanarak hareket eder.
