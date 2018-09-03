function $$(id){
    return document.getElementById(id);
  }
function pageLoad(){
    var can = $$('can');
    var cans = can.getContext('2d');
    cans.moveTo(20,30);//第一个起点
    cans.lineTo(120,90);//第二个点
    cans.lineTo(220,60);//第三个点（以第二个点为起点）
    cans.lineWidth=3;
    cans.strokeStyle = 'red';
    cans.stroke();
}