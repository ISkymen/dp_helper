jQuery(document).ready(function($) {

   // Add an "input" method to all jQuery objects
   $.fn.input = function (handler) {

      // iterate over all DOM elements in the jQuery object
      this.each( function () {
         // set a new method to run when "oninput" is fired
         this.oninput = function (prevHandler) {
            return function (ev) {
               // call previous handler if exists
               if( typeof prevHandler === 'function' ) {
                  prevHandler.call (this, ev);
               }
               // call new handler
               handler.call (this, ev);
            };
         }(this.oninput);  // immediate evaluation, pass current handler as argument
      });
   };

    $('#edit-title').input (function () {
      var len = $(this).val().length;

      /*
          45-65 - зеленый.
          39-44 и 66-71 желтый
          До 38 и после 72 - красный.
       */

      // Stage 1
      if (len >= 45 && len <= 65) {
        $(this).addClass('title-green');
        $(this).removeClass('title-yellow');
        $(this).removeClass('title-gray');
      }

      // Stage 2
      if ((len >= 39) && (len <= 44) || (len >= 66) && (len <= 71)) {
        $(this).addClass('title-yellow');
        $(this).removeClass('title-green');
        $(this).removeClass('title-gray');
      }

      // Stage 3
      if (len <= 38 || len >= 72) {
        $(this).addClass('title-gray');
        $(this).removeClass('title-green');
        $(this).removeClass('title-yellow');
      }

      console.log (len);
   });
});
