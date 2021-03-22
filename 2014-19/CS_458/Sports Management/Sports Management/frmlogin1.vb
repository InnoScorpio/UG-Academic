Public Class frmlogin1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If ComboBox1.Text = "" Then
            MsgBox("Enter usertype")
        ElseIf txtname.Text = "" Then
            MsgBox("Enter the username")
        ElseIf txtpass.Text = "" Then
            MsgBox("Enter the password")
        Else
            sql = "select * from tbl_reg where usertype='" & ComboBox1.Text & "' and username='" & txtname.Text & "' and password='" & txtpass.Text & "'"
            If rs.State = 1 Then rs.Close()
            rs.Open(sql, conn)
            If rs.EOF = False Then


                If ComboBox1.Text = "ADMIN" Then

                    Me.Hide()
                    frmwelcome.Show()
                    'ComboBox1.SelectedIndex = -1
                    'txtname.Text = ""
                    txtpass.Text = ""

                ElseIf ComboBox1.Text = "EMPLOYEE" Then
                    Me.Hide()

                    'menuform.PAYROLLToolStripMenuItem.Visible = False
                    frmwelcome.MASTERToolStripMenuItem.Visible = False
                    ' frmwelcome.REPORTSToolStripMenuItem.Visible = False
                    frmwelcome.Show()
                    'ComboBox1.SelectedIndex = -1
                    'txtname.Text = ""
                    txtpass.Text = ""
                End If

            Else
                MsgBox("Login Failed")
            End If
        End If

    End Sub

    Private Sub frmlogin1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        opendb()

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        clear()

    End Sub
    Sub clear()
        ComboBox1.SelectedIndex = -1
        txtname.Text = ""
        txtpass.Text = ""

    End Sub
End Class