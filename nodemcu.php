<?php
date_default_timezone_set('Europe/Istanbul');

if($_GET['v'] == 1){

function siteConnect($site)
    {

        $ch = curl_init();
        $hc = "YahooSeeker-Testing/v3.9 (compatible; Mozilla 4.0; MSIE 5.5; Yahoo! Search - Web Search)";
        curl_setopt($ch, CURLOPT_REFERER, 'http://www.google.com');
        curl_setopt($ch, CURLOPT_URL, $site);
        curl_setopt($ch, CURLOPT_USERAGENT, $hc);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        $site = curl_exec($ch);
        curl_close($ch);
        
        
        // Veriyi parçalama işlemi
        preg_match_all('@<span class="">(.*?)</span>@si',$site,$totalm);
        
    $toplamsayi     = str_replace(".","", strip_tags($totalm[0][1]));
    $iyilesensayi   = str_replace(".","", strip_tags($totalm[0][5]));
    $vefat          = str_replace(".","", strip_tags($totalm[0][2]));
   
    $total =  $toplamsayi - $iyilesensayi - $vefat;
    $total = strip_tags($total);
    $total = number_format($total, 2, '', '.');
   
    echo "C19 KALAN ". $total;
     }
    
    $giris = siteConnect('https://covid19.saglik.gov.tr/');
    
  

}elseif($_GET['v'] == 2){
    
    
function siteConnect($site)
    {

        $ch = curl_init();
        $hc = "YahooSeeker-Testing/v3.9 (compatible; Mozilla 4.0; MSIE 5.5; Yahoo! Search - Web Search)";
        curl_setopt($ch, CURLOPT_REFERER, 'http://www.google.com');
        curl_setopt($ch, CURLOPT_URL, $site);
        curl_setopt($ch, CURLOPT_USERAGENT, $hc);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        $site = curl_exec($ch);
        curl_close($ch);
        
        
        // Veriyi parçalama işlemi
        preg_match_all('@<div class="tpt-time">(.*?)</div>@si',$site,$totalm);
        
      $imsak = strip_tags($totalm[0][0]);  
      $iftar = strip_tags($totalm[0][4]);
      
        $from       = date("H:i");
        $to         = $iftar;
        
        $totaliftar      = strtotime($to) - strtotime($from);
        $hoursiftar      = floor($totaliftar / 60 / 60);
        $minutesiftar    = round(($totaliftar - ($hoursiftar * 60 * 60)) / 60);


if($hoursiftar < 0 ){
    echo "_- iFTAR OLDU -_";
}else{


echo "iFTARA: ".$hoursiftar.':'.$minutesiftar. " DK";
}

     }
    
    $giris = siteConnect('https://namazvakitleri.diyanet.gov.tr/tr-TR/9206/ankara-icin-namaz-vakti'); // Burada kendi şehrinizi diyanetin sitesinden bularak yazabilirsiniz.

}else{
    
    $now = date('d-m-Y H:i');
 echo $now;
//echo saatFarki('19:52', $now).' DAKiKA';
}
