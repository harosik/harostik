#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8); // ��� ������ � ������� (UTF-8)
    SetConsoleCP(CP_UTF8); // ��� ����� � ���������� (UTF-8)
    int A;
    cout << "������� ����� �� 1 �� 1000 (� �������� ������� ���): ";
    cin >> A;
    // �������� �� ������������ ���������� �����
    if (A < 1 || A > 1000) {
        cout << "����� ��� ���������. ����������, ������� ����� �� 1 �� 1000." << endl;
        return 1;
    }
    // ��������� ��������� ����� � ���� ���������
    int low = 1;
    int high = 1000;
    int guess;
    int attempts = 0;
    cout << "� �������� ������� ���� �����! ��������� '�', ���� ��� ����� ������� �������, '�', ���� ��� ������� ���������, � '�', ���� � ������." << endl;
    while (true) {
        guess = (low + high) / 2;  // ������� �������� ����� low � high
        attempts++;
        cout << "��� ����� " << guess << "? (�/�/�): ";
        char response;
        cin >> response;
        if (response == '�') {
            high = guess - 1;  // ���� ��� ����� ������� �������, ��������� ��������
        }
        else if (response == '�') {
            low = guess + 1;  // ���� ��� ����� ������� ���������, ����������� ��������
        }
        else if (response == '�') {
            cout << "���! � ������ ���� ����� �� " << attempts << " �������!" << endl;
            break;  // ���� ����� �������, ������� �� �����
        }
        else {
            cout << "�������� ����. ����������, ������� '�' ��� ������� ��������, '�' ��� ������� ������ ��� '�' ��� �����������." << endl;
        }
    }
    return 0;
}