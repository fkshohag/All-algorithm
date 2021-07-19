const isUpperCase = (aCharacter) =>  {    
    return (aCharacter >= 'A') && (aCharacter <= 'Z');
}
const replaceAt = (str, index, ch) => {
    return str.replace(/./g, (c, i) => i == index ? ch : c);
}

const correct = (str) => {
    let result = '';
    str = str.replace(/\s+/g,' ');
    if(str.length > 0) {
         str = replaceAt(str, 0, str.charAt(0).toUpperCase())
         result += str[0];
    }
    for(let index = 1; index < str.length; index++) {
        if(isUpperCase(str.charAt(index))) {
            result += '. '+str.charAt(index); 
        }
         else {
            result += str.charAt(index);
        }
    }
    for(let index = 0; index < result.length - 2; index++) {
        if(result[index] == '.') {
            result = replaceAt(result, index+2, result.charAt(index+2).toUpperCase())
        }
    }
    result = result.replace(' .','.');
    console.log(result);
}
correct("John have   an apple The sky  is blue.    they get a coin")
