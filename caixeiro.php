<?php
function caixeiro($cidades) {
    $custo = 0;
    
    $cidade_atual = key($cidades);
    $cidade_original = $cidade_atual;    
    
    while(!empty($cidades)) {
        $saidas_da_cidade_atual = $cidades[$cidade_atual];
        $menor_custo = max($saidas_da_cidade_atual);
        $proxima_cidade = '';
        
        foreach($saidas_da_cidade_atual as $cidade => $custo) {
            $nao_visitei = isset($cidades[$cidade]);
            if($nao_visitei && $custo <= $menor_custo) {
                $menor_custo = $custo;
                $proxima_cidade = $cidade;
            }
        }
        unset($cidades[$cidade_atual]);
        
        if (empty($cidades))
            $custo += $saidas_da_cidade_atual[$cidade_original];
        else
            $custo += $menor_custo;
        $cidade_atual = $proxima_cidade;
    }
    
    return $custo;
    
}
