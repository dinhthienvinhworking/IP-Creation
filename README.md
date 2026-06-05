# Lab04 - HW/SW Co-design trên Zynq

Repo này lưu phần đã thực hiện cho Lab 4 với Vivado/Vitis 2022.2:

- Tạo custom AXI4-Lite IP `led_controller` bằng Verilog.
- Tích hợp IP với Zynq Processing System.
- Viết ứng dụng C dùng `Xil_Out32` để điều khiển LED.
- Tạo IP `nco` bằng Vitis HLS và export thành Vivado IP.
- Tài liệu hướng dẫn tiếng Việt: `Lab04_Vivado_2022_2_Verilog.md`.

## Cấu Trúc

```text
Lab04_Vivado_2022_2_Verilog.md  Tài liệu hướng dẫn đã cập nhật cho Vivado/Vitis 2022.2
sources/hls_nco/                 Source C++ và testbench cho bài 4C
ip_repo/led_controller_1_0/       IP AXI4-Lite LED controller từ bài 4A
ip_repo/hls_nco_ip/               IP NCO export từ Vitis HLS
hls_nco_export/export.zip         Gói IP NCO dạng zip
tutorial4_extract/figures/        Hình minh họa nhỏ dùng trong tài liệu Markdown
```

`Tutorial 4.pdf` và các trang render đầy đủ không được đưa vào repo.

## Ghi Chú

Phần 4B cần MATLAB/Simulink/HDL Coder desktop nên nếu không có license/công cụ tương ứng thì chỉ trình bày quy trình lý thuyết. Phần 4A và 4C có thể thực hiện bằng Vivado/Vitis 2022.2.
