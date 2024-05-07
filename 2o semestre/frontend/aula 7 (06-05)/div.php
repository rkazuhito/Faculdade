<?php
$i=0;
$nums = [];
for ($i=0; $i < 501; $i++) { 
    if ($i %4 == 0 && $i % 9 == 0) {
        array_push($nums,$i);
    }
}
echo implode(',', $nums);
?>