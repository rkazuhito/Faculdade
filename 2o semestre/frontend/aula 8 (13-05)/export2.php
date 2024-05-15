<?php
$handle = fopen("formulario.txt","a+");
$nome = "Rafael";
$idade = "27";
$sexo = "M";

$export = $nome . "|" . $idade . "|" . $sexo ."\n";
if (strlen($export) == fwrite($handle, $export)){
    echo "deu boa";
}
fclose($handle);
?>