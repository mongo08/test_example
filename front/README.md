### Команда для запуска видео потока `gst-launch-1.0 filesrc location=/home/user/test_example/front/drift_rx7.mp4 ! decodebin ! queue ! videoconvert ! jpegenc ! queue ! rtpjpegpay ! udpsink host=127.0.0.1 port=8554`
### Воспроизведение из картинок `gst-launch-1.0 multifilesrc location=/home/user/test_example/front/test_video/img%03d.jpg loop=true start-index=1 !  decodebin ! queue ! videoconvert ! videorate ! "video/x-raw,framerate=30/1" ! jpegenc ! queue ! rtpjpegpay ! udpsink host=127.0.0.1 port=8554`
### Команда для разбивки видео на кадры `ffmpeg -i drift_rx7.mp4 img%03d.jpg`
### Для работы утилиты для распаковки zip архивов нужно установить `sudo apt-get install libzip-dev`
### Запуск тестов осуществляется командой ` ./back_test` из папки `test` расположенная в папке `build`