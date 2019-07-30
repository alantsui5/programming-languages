var app = new Vue({
    el: '#app',
    data: {
      message: 'Hello Brother!',
      seen:true,
      status:'Shown'
    },
    methods:{
        toggleSeen: function(){
            this.seen = !this.seen
            if(this.seen ==false){
                this.status = 'Hidden'
            }
            else{
                this.status = 'Shown'
            }
        }
    }
  })