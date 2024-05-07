<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body {
            background-color: peru;
        }

        form {
            width: 50%;
            display: block;
            margin: auto;
            align-content: center;
            background-color: white;
            padding-top: 12px;
            border-radius: 15px;
            text-align: center;
        }

        div {
            margin: 15px;
        }
    </style>
</head>

<body>

    <?php

    if (@$_REQUEST['botao']) {
        $valor1 = $_POST["valor1"];
        $valor2 = $_POST["valor2"];
        $result = $valor1 + $valor2;

        if($result>=0){
            echo "+";
        }
        else{
            echo "-";
        }
    }
    if(@$_REQUEST['cond']){
        $valor1 = $_POST["valor1"];
        $valor2 = $_POST["valor2"];
        $pares = [];
        for($valor1 ; $valor1<=$valor2 ; $valor1++){
            if ($valor1 % 2 == 0) {
                array_push($pares, $valor1);
            }            
        }
    }
    
    
    ?>

    <form action="#" method="post">
        <div>
            v1: <input type="number" name="valor1"> <br>
            v2: <input type="number" name="valor2"> <br> <br>
            <input type="submit" name="botao" value="RESULTADO"> 
            <input type="submit" name="cond" value="PARES"> <br>
            <input type="text" name="resultado" value="<?php echo @$result; ?>"> <br>
            <input type="text" name="pares" value="<?php echo implode(',', $pares); ?>"> <br>

            
        </div>
    </form>


</body>

</html>