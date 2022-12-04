int numToId(int num[]){
  
  String nums = String(num[0]) + String(num[1])+ String(num[2])+ String(num[3]);
  Serial.println(nums);
  if(nums.equals("0000")) return 1;
  if(nums.equals("0001")) return 2;
  if(nums.equals("0002")) return 3;
  if(nums.equals("0111")) return 4;
  if(nums.equals("0112")) return 5;
  if(nums.equals("0113")) return 6;
  if(nums.equals("0114")) return 7;
  if(nums.equals("0115")) return 8;
  if(nums.equals("0116")) return 9;
  if(nums.equals("0117")) return 10;
  if(nums.equals("0120")) return 11;
  if(nums.equals("0121")) return 12;
  if(nums.equals("0118")) return 13;
  if(nums.equals("0119")) return 14;
  if(nums.equals("0122")) return 15;
  if(nums.equals("0123")) return 16;
  if(nums.equals("0130")) return 17;
  if(nums.equals("0131")) return 18;
  if(nums.equals("0132")) return 19;
  if(nums.equals("0133")) return 20;
  if(nums.equals("1121")) return 21;
  if(nums.equals("1131")) return 22;
  if(nums.equals("1151")) return 23;
  if(nums.equals("1152")) return 24;
  if(nums.equals("1171")) return 25;
  if(nums.equals("1181")) return 26;
 
}
