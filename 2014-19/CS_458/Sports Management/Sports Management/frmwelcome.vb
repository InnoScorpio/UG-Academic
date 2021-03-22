Public Class frmwelcome

    Private Sub Label1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label1.Click
        pnlgames.Hide()

    End Sub

    Private Sub GAMESToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles GAMESToolStripMenuItem.Click
        pnlgames.Show()

    End Sub

    Private Sub frmwelcome_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        pnlgames.Hide()

    End Sub

    Private Sub PLAYERSToolStripMenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem3.Click
        frmbad.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem4.Click
        frmbadtour.Show()

    End Sub

    Private Sub PLAYERSToolStripMenuItem4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem4.Click
        frmbasket.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem5.Click
        frmbaskettour.Show()

    End Sub

    Private Sub COLLEGEToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles COLLEGEToolStripMenuItem.Click
        frmcollege.Show()

    End Sub

    Private Sub PLAYERSToolStripMenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem5.Click
        frmcplyr.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem6.Click
        frmcrtour.Show()

    End Sub

    Private Sub PLAYERSToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem.Click
        frmfplyr.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem1.Click
        frmfttour.Show()

    End Sub

    Private Sub PLAYERSToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem1.Click
        frmhockeyplyr.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem2.Click
        frmhtour.Show()

    End Sub

    Private Sub LOGINREGISTRATIONToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LOGINREGISTRATIONToolStripMenuItem.Click
        frmloginreg.Show()

    End Sub

    Private Sub STATEToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles STATEToolStripMenuItem.Click
        frmstate.Show()

    End Sub

    Private Sub STUDENTREGISTRATIONToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles STUDENTREGISTRATIONToolStripMenuItem.Click
        frmstudentreg.Show()


    End Sub

    Private Sub TOURNAMENTToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem.Click
        frmtour.Show()

    End Sub

    Private Sub PLAYERSToolStripMenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PLAYERSToolStripMenuItem2.Click
        frmvolleyplr.Show()

    End Sub

    Private Sub TOURNAMENTToolStripMenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TOURNAMENTToolStripMenuItem3.Click
        frmvltour.Show()

    End Sub

    Private Sub LOGOUTToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LOGOUTToolStripMenuItem.Click

        If MsgBoxResult.No = MsgBox("DO YOU WANT TO LOGOUT?", MsgBoxStyle.YesNo, " MMS") Then Exit Sub

        Me.Close()
        frmlogin1.Show()
    End Sub

    Private Sub EXITToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles EXITToolStripMenuItem.Click
        If MsgBoxResult.No = MsgBox("DO YOU WANT TO EXIT?", MsgBoxStyle.YesNo) Then Exit Sub
        Application.Exit()
    End Sub

    Private Sub PHOTOSToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PHOTOSToolStripMenuItem.Click
        frmfootballphotos.Show()

    End Sub

    Private Sub PHOTOSToolStripMenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PHOTOSToolStripMenuItem5.Click
        frmcrphotos.Show()

    End Sub

    Private Sub PHOTOSToolStripMenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PHOTOSToolStripMenuItem2.Click
        frmvophotos.Show()

    End Sub

    Private Sub PHOTOSToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PHOTOSToolStripMenuItem1.Click
        frmhopho.Show()

    End Sub

    Private Sub PHOTOSToolStripMenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PHOTOSToolStripMenuItem3.Click
        frmbadphoto.Show()

    End Sub

    Private Sub PHOTOSToolStripMenuItem4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles PHOTOSToolStripMenuItem4.Click
        frmbasketphotos.Show()

    End Sub
End Class