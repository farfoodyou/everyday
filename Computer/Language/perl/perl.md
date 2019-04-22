/i：不区分大小写
/g：匹配多次

my $count = my @array = $string =~ m/.../g; 
可以打印出捕获的数量

perl -ne '@arr = $_ =~ /bsp_personal, T_(\w+), \d+, (\d+), \d+/g;$i=0;foreach $item (@arr) {if($i%2==0){print \"$item\t\"} else {print \"$item\n\"} $i++;}'
