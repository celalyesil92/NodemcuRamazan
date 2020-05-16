# Nodemcu ile İftar vakti ve Türkiyedeki aktif Corona hasta sayısını gösterme

Bu uygulamamızda Nodemcu geliştirme kartını kullanarak LCD 16x2 ekran'a diyanet'in ve sağlık bakanlığının sitesinden çektiğimiz verileri göstermiş oluyoruz.

## Bağlantı Şekli
LCD ekran;
SCL -> D1
SDA -> D2
VCC -> VV
GND -> G

Bu projede ekstra olarak sıcaklık ve nem ölçer'de kullandım. Bunun bağlantısıda şu şekilde;
Bacaklar aşağıya gelecek şekilde bakıldığında;
1. Bacak -> D4
2. Bacak -> 3V
3. Bacak -> G

Bağlantıları bu şekilde yaptıktan sonra php dosyasını kendi sitenize upload etmeniz gerekmektedir. Ardından ino dosyasındaki site adreslerini güncelledikten sonra nodemcuya yükleyerek çalışır hale getirebilirsiniz.

