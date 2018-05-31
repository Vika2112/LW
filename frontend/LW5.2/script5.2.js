window.onload = function() {
  console.log('Документ и все ресурсы загружены');
    initFormFields();
}

//назначаем все "обработчики"
document.getElementById('submit').addEventListener('click',  validateForm);
document.getElementById('button_movies').addEventListener('click', performButtonClick);
document.getElementById('pop_light').addEventListener('click',  showModalWindow);
document.getElementById('close').addEventListener('click',  closeModalWindow);
document.getElementById('username').addEventListener('click', changeField);
document.getElementById('useremail').addEventListener('click', changeField);
document.getElementById('message').addEventListener('click', changeField);


function changeField() {
  var control = document.getElementsByClassName('form_control'); 
  for (var count = 0; count < control.length; count++) { 
    if ( control[count].value == '' ) { 
      control[count].classList.add('my_error'); 
      valid = false; 
    } 
    else{ 
      control[count].classList.remove('my_error'); 
    } 
      
  } 
}

function initFormFields() {
    var control = document.getElementsByClassName('form_control'); 
      for (var count = 0; count < control.length; count++) { 
          control[count].addEventListener('click', normalColor);
      }
}

//проверка формы на пустые поля
function validateForm() { 
  var valid = true; 
  var control = document.getElementsByClassName('form_control'); 
  for (var count = 0; count < control.length; count++) { 
    if ( control[count].value == '' ) { 
      control[count].classList.add('my_error'); 
      valid = false; 
    } 
    else{ 
      control[count].classList.remove('my_error'); 
    } 
  } 
  if (valid) { 
    closeModalWindow(); 
  } 
    else {
        event.preventDefault();
    }
        
}


function performButtonClick() {
    document.getElementById('button_movies').style = 'display:none';
    document.getElementById('box_movies').style = 'display:block';
    opacity(document.getElementById('box_movies'), 100);
}

function opacity(element, speed){
  setInterval(function(){
      if(+element.style.opacity<1){
          element.style.opacity = +element.style.opacity + 0.05;
      }
  }, speed)
}

//3. Модальное окно (popup)*/

function showModalWindow(){
  var darkLayer = document.createElement('div'); // слой затемнения
  darkLayer.className = 'shadow'; // class  чтобы подхватить стиль
  darkLayer.setAttribute("id", "darkLayer");
  document.body.appendChild(darkLayer); // включаем затемнение в конце родителя
  var modalWindow = document.getElementById('popup_contact'); // находим наше "окно"
  modalWindow.style.display = 'block'; // "включаем" его
  darkLayer.onclick = function() { // при клике на слой затемнения все исчезнет
    darkLayer.parentNode.removeChild(darkLayer); // удаляем затемнение
    modalWindow.style.display = 'none'; // делаем окно невидимым
    return false;
  };
}

function closeModalWindow() {
  var element = document.getElementById('darkLayer');
  element.parentNode.removeChild(element);
  document.getElementById('popup_contact').style.display = 'none';
}

function normalColor() {
    this.classList.remove('my_error');
}



